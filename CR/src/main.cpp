#include "truck.h"

int main()
{
    TruckDataBase truck_db = TruckDataBase("../dbs/truckdb.csv");
    truck_db.list.Print(10);

    return 0;
 }
