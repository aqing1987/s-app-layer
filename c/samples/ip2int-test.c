/**
 * int inet_aton(const char *cp, struct in_addr *inp);
 *    inet_aton() converts the internet host address cp from the IPv4
 *    numbers-and-dots notation into binary form (int network byte order)
 *    and stores it in the structre that inp points to.
 *    returns nonzero if the address is valid, zero if not.
 *
 * char *inet_ntoa(struct in_addr in);
 *    the inet_ntoa() function converts the Internet host address in,
 *    given in network byte order, to a string in IPv4 dotted-decimal
 *    notation. The string is returned in a statically allocated buffer,
 *    which subsequent calls will overwrite.
 *
 * typedef uint32_t in_addr_t;
 *
 * struct in_addr {
 *     in_addr_t s_addr;
 * };
 *
 */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * $ ./ip2int-test 192.168.1.100
 *   192.168.1.100 - 1677830336
 * $ ./ip2int-test 255.255.255.0
 *   255.255.255.0 - 16777215
 * */
int main(int argc, char *argv[])
{
    struct in_addr addr;

    if (argc != 2) {
        printf("Usage: %s ip\n", argv[0]);
        return -1;
    }

    if (inet_aton(argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        return -1;
    }

    // uint32_t ntohl(uint32_t netlong);
    uint32_t ipval=0;
    ipval = ntohl(addr.s_addr);
    printf("%s - %u\n", argv[1], ipval);

    printf("%u - %s\n", ipval, inet_ntoa(addr));

    return 0;
}
