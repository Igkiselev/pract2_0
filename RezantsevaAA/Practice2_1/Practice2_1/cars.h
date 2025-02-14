#ifndef _CARS_H
#define _CARS_H

typedef struct
{
    char* brand;
    char* color;
    char* serial_number;
    char* registration_number;
    int count_door;
    int year;
    int price;
} Car;

char* read_string(FILE* stream);
char* getPath();
Car ReadCarEntity(FILE* file);
Car* ReadCarFile(char* file_path, int* number_of_cars);
Car FindOldestCar(Car* cars, int count_of_cars);
void PrintCar(Car car);

#endif _CARS_H