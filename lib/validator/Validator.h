/**
 * @author Leonardo Menezes
 * @email leonardosmenezes.ssz@gmail.com
 * @create date 2020-10-12 00:03:20
 * @modify date 2020-10-12 00:03:20
 */

 #include <map>

 
 bool isAValidLigthKey(String parameter, std::map<String, int> lights){
        std::map<String, int>::iterator it = lights.find(parameter);

        if (it == lights.end()){
            return false;
        }

        return true;
    } 

  bool isAValidTension(String tension){
       return tension == "0" || tension == "1";
    }