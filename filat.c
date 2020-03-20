#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>


const char* type(struct stat attributes)
{
  if(S_ISREG(attributes.st_mode))
  {
    return "regular file";
  }
  if(S_ISDIR(attributes.st_mode))
  {
      return "directory";
  }
  if(S_ISCHR(attributes.st_mode)) 
  {
      return "character device";
  }
  if(S_ISBLK(attributes.st_mode))
  {
      return "block device";
  }
  if(S_ISFIFO(attributes.st_mode))
  {
      return "first in first out";
  }
  if(S_ISLNK(attributes.st_mode))
  {
    return "symlink";
  }
  return "not found";
}

int main(int argc, char const *argv[]) 
{
  struct stat atrbts;

  if(stat(argv[1], &atrbts) != 0)
  {
   printf("File '%s' existiert nicht\n", argv[1]);
  }
  else
  {
     printf("file type        : %s\n", type(atrbts));
    printf("Access privileges: ");
    printf( (S_ISDIR(atrbts.st_mode)) ? "d" : "-");
    printf( (atrbts.st_mode & S_IRUSR) ? "r" : "-");
    printf( (atrbts.st_mode & S_IWUSR) ? "w" : "-");
    printf( (atrbts.st_mode & S_IXUSR) ? "x" : "-");
    printf( (atrbts.st_mode & S_IRGRP) ? "r" : "-");
    printf( (atrbts.st_mode & S_IWGRP) ? "w" : "-");
    printf( (atrbts.st_mode & S_IXGRP) ? "x" : "-");
    printf( (atrbts.st_mode & S_IROTH) ? "r" : "-");
    printf( (atrbts.st_mode & S_IWOTH) ? "w" : "-");
    printf( (atrbts.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("File size        : %ld\n",(long) atrbts.st_size);
    printf("inode-Number     : %ld\n",(long) atrbts.st_ino);
    printf("Link count       : %ld\n",(long) atrbts.st_nlink);
    printf("UID              : %ld\n",(long) atrbts.st_uid);
    printf("GID              : %ld\n",(long) atrbts.st_gid);
    printf("Device Number    : %ld\n", atrbts.st_dev);
    printf("Latest access    : %s",ctime(&atrbts.st_atime));
    printf("Last inode change: %s",ctime(&atrbts.st_ctime));
    printf("Last mod         : %s",ctime(&atrbts.st_mtime));
  }

  return 0;
}

