/**
 * @author Leonardo Menezes
 * @email leonardosmenezes.ssz@gmail.com
 * @create date 2020-10-12 00:03:58
 * @modify date 2020-10-12 00:03:58
 */

#include <Nodemcu.h>
#include <Constants.h>
#include <ESP8266WebServer.h>
#include <Validator.h>

Nodemcu nodemcu(115200, D1, D3, D2);
ESP8266WebServer server(80);

 
 void handlerLigthsRequests(){
    String parameterName = server.argName(0);
    String parameterValue = server.arg(parameterName);

    if (!isAValidLigthKey(parameterName, nodemcu.lights)){
      server.send(400, JSON, INVALID_LIGHT);
      return;
    }

    if (!isAValidTension(parameterValue)){
      server.send(400, JSON, INVALID_TENSION);
      return;
    }

    nodemcu.changeLigthPower(parameterName, parameterValue);
    server.send(200, JSON, SUCCESS);
  }

  void handlerNotFound(){
    server.send(404, JSON, NOT_FOUND);
  }


void setup() {

  nodemcu.initTrafficLigths();
  nodemcu.wifiBegin("*************", "*************");
  nodemcu.showIP();

  server.on("/lights", handlerLigthsRequests);
  server.onNotFound(handlerNotFound);
  server.begin();
}

void loop() {
  server.handleClient();
}

