#include <map>


std::map<String, int> lights = {
    {"green", D1},
    {"yellow", D3},
    {"red", D2}
  };


const String INVALID_TENSION_MSG = "Invalid tension, please choose 1 to turn on and 0 to turn off the ligth.";
const String INVALID_LIGHT_KEY_MSG = "Invalid ligth parameter, please send green, red or yellow.";

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
 

    std::map<String, String> evaluateParams(String litghName, String lightTension){
        if (!isAValidLigthKey(litghName)){
            return {{"status", "400"}, {"message", INVALID_LIGHT_KEY_MSG}};
        } else if (!isAValidTension(lightTension)){
            return {{"status","400"}, {"message", INVALID_TENSION_MSG}};
        }else{
            return {{"status", "200"}, {"message", "The ligth " + litghName + " has changed power to " + lightTension}};
    }
} 

};
























