#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>



int print(char open[100], char dirname[100], char filename[100]){
  DIR * d = opendir(open);
  if (errno == -1) {
      printf("%s\n", strerror(errno));
      return -1;
  }
  struct dirent * directory;
  int size = 0;

  while((directory = readdir(d)) != NULL){
    struct stat file;
    stat(directory->d_name, &file);
    if(directory->d_type == 4){
      strcat(dirname, "\n");
      strcat(dirname, directory->d_name);

    }else{
      strcat(filename,"\n");
      strcat(filename, directory->d_name);
    }
    size += file.st_size;
  }

  return size;

}
int main(int argc, char * argv[]){
  char open[100];
  char dirname[100] = "";
  char filename[100] = "";
  if(argc <=1){
    printf("What Directory?\n ");
    fgets(open,sizeof(open),stdin);
    open[strlen(open)-1] = 0;

  }else{
    strcpy(open, argv[1]);
  }

  int a = print(open, dirname, filename);
  printf("size: %ul bytes\n", a);
  printf("directories: %s\n", dirname);
  printf("reg files: %s\n", filename);
  return 0;
}