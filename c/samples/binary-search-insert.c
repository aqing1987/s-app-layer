#include <stdio.h>

// binary search
// arr: array
// len: array len
// value: item to find
//
// return: item position
int SearchItem(int arr[], int len, int value) {
  int low = 0, high = len -1, mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (value > arr[mid]) {
      low = mid + 1;
    } else if (value < arr[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

// get the insert position
//
// arr: array
// len: array len
// value: item to insert
//
int GetInsertItemLoc(int arr[], int len, int value) {
  int low = 0, high = len - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;
    if (value > arr[mid]) {
      low = mid + 1;
    } else if (value < arr[mid]) {
      high = mid - 1;
    } else {
      return mid + 1;
    }
  }

  return low;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 31, 38, 50, 60, 79, 90, 101};
  int pos = 0;

  int len = sizeof(arr) / sizeof(int);

  int i;
  for (i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");

  pos = SearchItem(arr, len, 60);
  if (pos < 0) {
    printf("SearchItem failed\n");
  } else {
    printf("%d\n", arr[pos]);
  }

  pos = GetInsertItemLoc(arr, len, 4);
  printf("should insert to %d\n", pos);

  return 0;
}
