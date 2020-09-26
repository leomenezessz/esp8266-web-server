#include <Arduino.h>
#include <Nodemcu.h>
#include <Response.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

Nodemcu nodemcu(115200);
ESP8266WebServer server(80);

 
 void handlerLigthsRequests(){
    String parameterName = server.argName(0);
    String parameterValue = server.arg(parameterName);
    std::map <String, String> nodemcuEvaluatedParams = nodemcu.evaluateParams(parameterName, parameterValue);

    if (nodemcuEvaluatedParams.at("status").equals("200")){
      nodemcu.changeLigthPower(parameterName, parameterValue);
    }

    Response resp = Response(nodemcuEvaluatedParams);
    server.send(resp.statusCode, resp.contentType, resp.body);
  }

  void handlerNotFound(){
    Response resp = notFoundResponse();
    server.send(resp.statusCode, resp.contentType, resp.body);
  }


void setup() {

  nodemcu.configureAllLigthsPinModeAsOutput();

  nodemcu.print("====== Starting connection =======");

  WiFi.begin("********", "*********");

  String connMessage = "connecting";

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    nodemcu.print(connMessage += ".");
  }

  nodemcu.print("====== Connected! ========");
  nodemcu.print(WiFi.localIP().toString());

  server.on("/lights", handlerLigthsRequests);
  server.onNotFound(handlerNotFound);
  server.begin();
  
}

void loop() {
  server.handleClient();
}


