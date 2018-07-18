#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cJSON.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u64;
typedef signed char s8;

#define REC_MAX_NUM       200

typedef struct ScanRecord {
  u8 tag_mac[6];
  s8 average_rssi;
  u8 adv_data[31];
  u8 samples;
  u8 pack[1];
} ScanRecordSt;

typedef struct TrackData {
  u64 timestamp;
  u8 ap_mac[6];
  u8 record_num;
  ScanRecordSt records[REC_MAX_NUM];
} TrackDataSt;

struct record {
  const char* timestamp;
  const char* type;
  const char* mac;
  const char* bleName;
  const char* ibeaconUuid;
  u16 ibeaconMajor;
  u16 ibeaconMinor;
  s8 ibaconTxPower;
  s8 rssi;
  u8 battery;
};

const char hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

void HexToStr(unsigned char* data, int len, char* out) {
  int i = 0;

  for (i = 0; i < len; i++) {
    out[2 * i]     = hexmap[(data[i] & 0xF0) >> 4];
    out[2 * i + 1] = hexmap[data[i] & 0x0F];
  }
}

static void GenerateTrackData(TrackDataSt* td) {
  td->timestamp = 1526018811;
  memcpy(td->ap_mac, "\x34\xe7\x0b\x7f\x1a\xcf", 6);
  td->record_num = 2;

  memcpy(td->records[0].tag_mac, "\x3d\xbb\x4d\xb4\xae\xe3", 6);
  td->records[0].average_rssi = -70;
  memcpy(td->records[0].adv_data,
         "\x02\x01\x06\x1a\xff\x4c\x00\x02\x15\x50\x4f\x4c\x45\x53\x54\x41\x52\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe4\x3f\xba\x00",
         31);
  td->records[0].samples = 4;

  memcpy(td->records[1].tag_mac, "\x04\xa3\x16\x0f\xe7\x20", 6);
  td->records[0].average_rssi = -82;
  memcpy(td->records[1].adv_data,
         "\x02\x01\x06\x1a\xff\x4c\x00\x02\x15\x50\x4f\x4c\x45\x53\x54\x41\x52\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa9\x9e\xba\x00",
         31);
  td->records[1].samples = 2;
}

static void Convert2json(TrackDataSt* td, char* json_full, int out_size) {
  if (td == NULL || json_full == NULL || out_size <= 0) return;

  cJSON* root = NULL;
  cJSON* fld = NULL;

  struct record rec;
  memset(&rec, 0, sizeof(rec));

  struct tm* timeinfo;
  time_t time_raw = td->timestamp;
  timeinfo = localtime(&time_raw);
  char time_buf[80];
  strftime (time_buf, 80, "%Y-%m-%dT%H:%M:%S%z", timeinfo);

  root = cJSON_CreateArray();

  for (int i = 0; i < td->record_num; i++) {
    if (td->records[i].adv_data[5] != 0x4C &&
        td->records[i].adv_data[6] != 0x00) {
      printf("not ibeacon\n");
      continue;
    }

    fld = cJSON_CreateObject();

    cJSON_AddStringToObject(fld, "timestamp", time_buf);
    cJSON_AddStringToObject(fld, "type", "ibeacon");
    char mac_str[16];
    memset(mac_str, 0, sizeof(mac_str));
    HexToStr(td->records[i].tag_mac, 6, mac_str);
    cJSON_AddStringToObject(fld, "mac", mac_str);

    cJSON_AddStringToObject(fld, "bleName", "");

    char uuid_str[36];
    memset(uuid_str, 0, sizeof(uuid_str));
    HexToStr(td->records[i].adv_data+9, 16, uuid_str);
    cJSON_AddStringToObject(fld, "ibeaconUuid", uuid_str);

    u16 major = *((u16*)(td->records[i].adv_data + 25));
    cJSON_AddNumberToObject(fld, "ibeaconMajor", major);

    u16 minor = *((u16*)(td->records[i].adv_data + 27));
    cJSON_AddNumberToObject(fld, "ibeaconMinor", minor);

    s8 txpower = td->records[i].adv_data[29];
    cJSON_AddNumberToObject(fld, "ibeaconTxPower", txpower);

    cJSON_AddNumberToObject(fld, "rssi", td->records[i].average_rssi);
    cJSON_AddNumberToObject(fld, "battery", 100);

    cJSON_AddItemToArray(root, fld);
  }

  // formatted print
  char* out = NULL;
  out = cJSON_Print(root);
  strncpy(json_full, out, out_size);

  cJSON_Delete(root);
}

int main(int argc, char *argv[]) {

  TrackDataSt td;
  memset(&td, 0, sizeof(td));
  GenerateTrackData(&td);

  char out[1024];
  memset(out, 0, sizeof(out));
  Convert2json(&td, out, 1024);
  printf("%s\n", out);

  return 0;
}
