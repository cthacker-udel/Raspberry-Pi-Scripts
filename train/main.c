#include "trainmethods.c"

int main(void){

    while(1){

        int choice;
        printMenu();
        scanf("%d",&choice);
        char *name = (char *)malloc(sizeof(char) * 1000);
        int weight;
        switch(choice){

            case 1:
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                scanf("%s",name);
                printf("\tEnter the weight of the train car\n");
                scanf("%d",&weight);
                addCar(createCar(weight,name));
                break;
            
            case 2:
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                scanf("%d",&weight);
                deleteCar(createCar(weight,name));
                break;

            case 3:
                reverseTrain();
                break;

            case 4:
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the weight of the car you want to find\n");
                scanf("%d",&weight);
                car *foundCar = findCar(weight);
                printf("\n\tThe train car found is : NAME[%s] weighing %d pounds\n",foundCar->name,foundCar->weight);
                break;

            case 5:
                sortCars();
                break;

            case 6:
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
                scanf("%d",&weight);
                addHead(createCar(weight,name));
                break;

            case 7:
                printf("\n\n### USER INPUT ###\n\n");
                printf("\tEnter the name of the train car\n");
                fgets(name,1000,stdin);
                printf("\tEnter the weight of the train car\n");
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