#include <Arduino.h>
#include <ESP8266WebServer.h>


const String JSON_CONTENT_TYPE = "application/json";
const String INVALID_TENSION_MSG = "Invalid tension, please choose 1 to turn on and 0 to turn off the ligth.";
const String INVALID_LIGHT_KEY_MSG = "Invalid ligth parameter, please send green, red or yellow.";
const String RESOURCE_NOT_FOUND = "Resource not found.";

class Responser{

public:
    int statusCode;
    String body;
    String contentType;
};


Responser reponseGenerator(String parameterName, String parameterValue){

  Responser resp;
  resp.contentType = JSON_CONTENT_TYPE;
  resp.statusCode = 400;
  
  if (!isAValidLigthKey(parameterName)){
    resp.body = "{\"message\":\"" + INVALID_LIGHT_KEY_MSG + "\"}";
    return resp;
  } else if (!isAValidTension(parameterValue)){
    resp.body = "{\"message\":\"" + INVALID_TENSION_MSG + "\"}";
    return resp;
  }else{
    resp.statusCode = 200;
    resp.body = "{\"message\":\"The ligth " + parameterName + " has changed power to " + parameterValue + "\"}";
    return resp;
  }
};



Responser notFound(){
  Responser resp;
  resp.contentType = JSON_CONTENT_TYPE;
  resp.statusCode = 404;
  resp.body = "{\"message\":\"" + RESOURCE_NOT_FOUND + "\"}";
  return resp;
};

