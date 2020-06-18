#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <Wifi.h>
#include <Nodemcu.h>
#include <Responser.h>



Nodemcu nodemcu(115200);
ESP8266WebServer server(80);
Wifi wifi("*******", "**********");

 
 void handlerLigthsRequests(){
    String parameterName = server.argName(0);
    String parameterValue = server.arg(parameterName);
    Responser resp = reponseGenerator(parameterName, parameterValue);

    if (resp.statusCode == 200){
      nodemcu.changeLigthPower(parameterName, parameterValue);
    }

    server.send(resp.statusCode, resp.contentType, resp.body);
  }


  void handlerNotFound(){
    Responser resp = notFound();
    server.send(resp.statusCode, resp.contentType, resp.body);
  }


void setup() {

  nodemcu.configureAllLigthsPinModeAsOutput();

  nodemcu.print("Starting connection...");
  
  wifi.waitConnection(500);

  nodemcu.print(wifi.showIP());

  server.on("/ligths", handlerLigthsRequests);

  server.onNotFound(handlerNotFound);

  server.begin();
  
}

void loop() {
  server.handleClient();
}


