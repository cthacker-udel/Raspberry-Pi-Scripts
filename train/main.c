#include "project.h"


int main(void){

    while(1){

        int choice;
        printMenu();
        scanf("%d",&choice);
        switch(choice){

            case 1:
                char *name;
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                int weight;
                scanf("%d",&weight);
                addCar(createCar(weight,name));
                break;
            
            case 2:
                char *name;
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                int weight;
                scanf("%d",&weight);
                deleteCar(createCar(weight,name));
                break;

            case 3:
                reverseTrain();
                break;

            case 4:
                int weight;
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the weight of the car you want to find\n");
                scanf("%d",&weight);
                int index = findCar(weight);
                printf("\n\tThe train car is located at index : %d\n",index);
                break;

            case 5:
                sortCars();
                break;

            case 6:
                char *name;
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                int weight;
                scanf("%d",&weight);
                addHead(createCar(weight,name));
                break;

            case 7:
                char *name;
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                int weight;
                scanf("%d",&weight);
                addTail(createCar(weight,name));
                break;

            case 8:
                removeHead();
                break;

            case 9:
                removeTail();
                break;

            case 10:
                displayTrain();
                break;
                
            default:
                return 1;
        }

    }


    return 1;

}