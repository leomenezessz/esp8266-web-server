#include <Arduino.h>
#include <ESP8266WiFi.h>


class Wifi{

public:
    Wifi(String ssid, String pass){
        WiFi.begin(ssid, pass);
    }

    void waitConnection(int millisDelay){
        while (WiFi.status() != WL_CONNECTED){
            delay(millisDelay);
            Serial.print(".");
        }
    }

    String showIP(){
        return WiFi.localIP().toString();
    }
};




