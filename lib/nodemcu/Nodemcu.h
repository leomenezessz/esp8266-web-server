#include <map>
#include <Arduino.h>

std::map<String, int> lights = {
    {"green", D1},
    {"yellow", D3},
    {"red", D2}
  };


class Nodemcu{

    public:
        Nodemcu(int baud){
        Serial.begin(baud);   
    }

    void configureAllLigthsPinModeAsOutput(){
        std::map<String, int> :: iterator it; 

        for ( it = lights.begin(); it != lights.end(); it ++){
            pinMode(it->second, OUTPUT);
        };
    }

    void changeLigthPower(String ligthName, String power){
        digitalWrite(lights.at(ligthName), power.toInt());   
    }

    void print(String msg){
        Serial.println(msg);
    }  

};

 bool isAValidLigthKey(String parameter){
        std::map<String, int>::iterator it = lights.find(parameter);

        if (it == lights.end()){
            return false;
        }

        return true;
    } 


 bool isAValidTension(String tension){
        if (tension == "0" || tension == "1"){
            return true;
        }
        return false;
    }     






















