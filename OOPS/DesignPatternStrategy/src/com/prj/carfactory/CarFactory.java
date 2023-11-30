package com.prj.carfactory;

import com.prj.car.Car;
import com.prj.carmodels.HatchBack;
import com.prj.carmodels.SUV;
import com.prj.carmodels.Sedan;

enum model{
    SEDAN,
    SUV,
    HATCHBACK
}

public class CarFactory {

    public static Car constructCar(com.prj.modelenum.model model){
        Car car = null;

        switch (model) {
            case SEDAN:
                car = new Sedan();
                break;
            case SUV:
                car = new SUV();
                break;
            case HATCHBACK:
                car = new HatchBack();
                break;
            default:
                break;
        }
        return car;

    }
}
