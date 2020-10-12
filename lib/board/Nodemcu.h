/**
 * @author Leonardo Menezes
 * @email leonardosmenezes.ssz@gmail.com
 * @create date 2020-10-12 00:02:35
 * @modify date 2020-10-12 00:02:35
 */


#include <map>
#include <ESP8266WiFi.h>
using namespace std;


class Nodemcu{

    public:
        std::map<String, int> lights; 

    public:
        Nodemcu(int baud, int green, int red, int yellow){
        Serial.begin(baud);   
        lights.insert(pair<String, int> ("green", green));
        lights.insert(pair<String, int> ("red", red));
        lights.insert(pair<String, int> ("yellow", yellow));
    }

    void initTrafficLigths(){
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


    void wifiBegin(String ssid, String password){
         WiFi.begin(ssid, password);

        String connMessage = "connecting";

        while (WiFi.status() != WL_CONNECTED){
            delay(500);
            print(connMessage += ".");
        }
    }

    void showIP(){
        print(WiFi.localIP().toString());
    }
};
























