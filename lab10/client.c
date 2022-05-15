#include <stdio.h>      /* printf, sprintf */
#include <stdlib.h>     /* exit, atoi, malloc, free */
#include <unistd.h>     /* read, write, close */
#include <string.h>     /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h>      /* struct hostent, gethostbyname */
#include <arpa/inet.h>
#include "helpers.h"
#include "requests.h"

int main(int argc, char *argv[])
{
    char *message;
    char *response;
    int sockfd;

    sockfd = open_connection("34.241.4.235", 8080, PF_INET, SOCK_STREAM, 0);

    message = compute_get_request("34.241.4.235:8080", "api/v1/dummy", NULL, NULL, 0);
    printf("%s", message);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s", response);
    char **body_data = malloc(2 * sizeof(char *));
    body_data[0] = "hello=there";
    body_data[1] = "mister=johnson";
    message = compute_post_request("34.241.4.235:8080", "api/v1/dummy", "application/x-www-form-urlencoded", body_data, 2, NULL, 0);
    printf("%s", message);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s", response);
    // Ex 1.1: GET dummy from main server
    // Ex 1.2: POST dummy and print response from main server
    // Ex 2: Login into main server
    // Ex 3: GET weather key from main server
    // Ex 4: GET weather data from OpenWeather API
    // Ex 5: POST weather data for verification to main server
    // Ex 6: Logout from main server

    // BONUS: make the main server return "Already logged in!"

    // free the allocated data at the end!

    return 0;
}
