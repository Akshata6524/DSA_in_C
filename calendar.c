#include<stdio.h>
typedef struct cal{
    char day[10];
    char activity[100];
}Activity;
int i;
void createCal(Activity cal[7]){
    for(i=0;i<7;i++){
        printf("Day -%d\n",i+1);
        printf("Day:");
        scanf("%s",cal[i].day);
        printf("Activity:");
        scanf("%s",cal[i].activity);
    }
}

void printCal (Activity cal[7]){
    printf("calendar for the week\n");
    for(i=0;i<7;i++){
        printf("%s:%s\n",cal[i].day,cal[i].activity);
    }
}

int main(){
    Activity cal[7];
    createCal( cal);
    printCal(cal);
    
}
