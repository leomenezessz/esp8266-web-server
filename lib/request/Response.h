#include <map>


const String JSON_CONTENT_TYPE = "application/json";
const String RESOURCE_NOT_FOUND = "Resource not found.";

class Response{

  public:
  int statusCode;
  String body, contentType;  

public:
  Response(std::map <String, String> nodemcuEvaluatedData){
    statusCode = std::atoi(nodemcuEvaluatedData.at("status").c_str()) ;
    body = "{\"message\":\"" + nodemcuEvaluatedData.at("message") + "\"}";
    contentType = JSON_CONTENT_TYPE;
  }  
};

Response notFoundResponse(){
  return Response({{"status", "404"},{ "message" , RESOURCE_NOT_FOUND}});
};

