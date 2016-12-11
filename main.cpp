#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>

using namespace std;

char file_buffer[256][256];

char filename[25];

char text_box_buffer[2048];

char *p;

bool working = true;

int num_lines = 0;

int option;

void text_box(char *name){
    text_box_buffer[0] = NULL;
    strcpy(text_box_buffer, name);
}

void Copy(char *d, char *s){
    int i=0;
    while(s[i] != ' '){
        d[i] = s[i];
        i++;
    }
    d[i] = NULL;
}

int main()
{
    text_box_buffer[0] = NULL;
    while(working){
        system("CLS");
        cout<<"1. Load file"<<endl;
        cout<<"2. Run file";
        if(filename[0] == NULL) cout<<" : No file loaded" <<endl;
        else cout<<" : "<<filename<<endl;
        cout<<"3. Exit "<<endl;
        if(text_box_buffer[0] != NULL){
            cout<<endl<<text_box_buffer<<endl<<endl;
        }
        cout<<"Enter opotion : ";
        cin>>option;
        cin.get();
        if(option == 1){
            text_box_buffer[0] = NULL;
            cout<<endl<<"Enter name file: ";
            cin.get(filename, 25);
            cin.get();
        }
        else if(option == 2){
            text_box_buffer[0] = NULL;
            num_lines = 0;
            if(filename[0] != NULL){
                ifstream file(filename);
                if(file.is_open()){
                    while(file.get(file_buffer[num_lines], 256)){
                        file.get();
                        num_lines++;
                    }
                    char cur[256], *p;
                    for(int i=0; i<num_lines; i++){
                        cur[0] = NULL;
                        strcpy(cur, file_buffer[i]);
                        p = strtok(cur, " ");
                        if(strcmp(cur, "print") == 0){
                            strcat(text_box_buffer, file_buffer[i] + strlen(p) + 1);
                        }
                        else if(strcmp(cur, "printEndLine") == 0){
                            strcat(text_box_buffer, file_buffer[i] + strlen(p) + 1);
                            strcat(text_box_buffer, "\n");
                        }
                        else if(strcmp(cur, "endline") == 0){
                            strcat(text_box_buffer, "\n");
                        }
                        else if(strcmp(cur, "end") == 0) break;

                    }
                }
                else text_box("No such file exists");
            }
        }
        else{
            exit(1);
        }
    }
    return 0;
}
