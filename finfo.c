/*
* Name: Ashwin Senthil
* Date: 11/3/2025
* Assignment: lab 9
*
* 
*
* compile instructions - makefile 
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_info;

    // retrieve file info
    if (stat(argv[1], &file_info) != 0) {
        perror("stat\n");
        return 1;
    }

    // file type
    printf("file type: ");
    if (S_ISREG(file_info.st_mode)) {
        printf("regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("symbolic link\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("character device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("block device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("fifo\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("socket\n");
    } else {
        printf("unknown type\n");
    }

    // permission

    // split into owner, group, and other permission slots

    // owner
    if (file_info.st_mode & S_IRUSR) {
        printf("- Owner has read permission\n");
    }
    if (file_info.st_mode & S_IWUSR) {
        printf("- Owner has write permission\n");
    }
    if (file_info.st_mode & S_IXUSR) {
        printf("- Owner has execute permission\n");
    }

    // group
    if (file_info.st_mode & S_IRGRP) {
        printf("- Group has read permission\n");
    }
    if (file_info.st_mode & S_IWGRP) {
        printf("- Group has write permission\n");
    }
    if (file_info.st_mode & S_IXGRP) {
        printf("- Group has execute permission\n");
    }

    // others
    if (file_info.st_mode & S_IROTH) {
        printf("- Others have read permission\n");
    }
    if (file_info.st_mode & S_IWOTH) {
        printf("- Others have write permission\n");
    }
    if (file_info.st_mode & S_IXOTH) {
        printf("- Others have execute permission\n");
    }

    // check bit
    if (file_info.st_mode & S_ISUID) {
        printf("- Set-UID bit is set\n");
    }
    if (file_info.st_mode & S_ISGID) {
        printf("- Set-GID bit is set\n");
    }
    if (file_info.st_mode & S_ISVTX) {
        printf("- Sticky bit is set\n");
    }

    // cttime for conversions!!!
    printf("OWNER UID: %d\n", file_info.st_uid);
    printf("File size: %ld\n", file_info.st_size);
    printf("Last modified: %s\n", ctime(&file_info.st_mtime));
    // uses ctime to convert timestamp to readable human time

    return 0;
}
