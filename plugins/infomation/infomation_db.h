
#ifndef PLUGINS_INFOMATION_MYSQL_H_
#define PLUGINS_INFOMATION_MYSQL_H_

#include "config/config.h"
#include "basic/basictypes.h"

#include "storage/data_engine.h"

#include "net/typedef.h"

namespace infomation_mysql {

class Infomation_Mysql {
 public:
  Infomation_Mysql(config::FileConfig* config);
  ~Infomation_Mysql();

  bool addstarinfo(const std::string& code,
  						const std::string& phone,
  						const std::string& name,
  						const int64 gender,
  						const std::string& brief_url,
  						const double price,
  						const std::string& accid,
  						const std::string& picurl);
  //��ȡ��˿����
  bool getfanscomments(const std::string& starcode,DicValue &ret,int64& startnum,int64& endnum);
  static void Callgetfanscomments(void* param, base_logic::Value* value);
  //��ȡȫ��������Ϣ
  bool getstarinfo(const std::string& code,const std::string& phone,DicValue &ret,int64 all);

  //��ȡbanner��Ϣ
  bool getbannerinfo(const std::string& code,DicValue &ret,int64 all);
  
  //��ȡԤԼ�����б�
  bool getorderstarinfo(const std::string& code,const std::string& phone,DicValue &ret);

  //��ȡ��ѯ�б�
  bool getstarnews(const std::string& code,const std::string& name,DicValue &ret,
  					int64& startnum,int64& endnum,int64& all);
  
  //��ȡ���Ƿ����б�
  bool getstarservicelist(const std::string& code, DicValue &ret);
  //�û��������Ƿ���
  bool userorderstarservice(const int64 uid, const std::string& starcode,const int64 mid,
  	        const std::string& cityname,const std::string& appointtime,const int64 meettype,
  	        const std::string& comment);
  					
  //��ȡ�û�����������
  bool getuserstaramount(const int64 uid, int64& num);
  
  //��ȡ�û�����ʱ��
  bool getuserstartime(const int64 uid, const std::string code, int64& time);
  
  //��ȡ����ʱ��
  bool getstartime(const std::string code, int64& time);
  
  static void Callpublicback(void* param, base_logic::Value* value);
  
  static void Callgetinfo(void* param, base_logic::Value* value);

  static void Callgetbannerinfo(void* param, base_logic::Value* value);

  static void Callgetorderstarinfo(void* param, base_logic::Value* value);

  static void Callgetstarnewsinfo(void* param, base_logic::Value* value);
  	
  static void Callgetstarservicelist(void* param, base_logic::Value* value);
  static void Calluserorderstarservice(void* param, base_logic::Value* value);
  static void Callgetuserstaramount(void* param, base_logic::Value* value);
  static void Callgetuserstartime(void* param, base_logic::Value* value);
  static void Callgetstartime(void* param, base_logic::Value* value);
  private:
  base_logic::DataEngine* mysql_engine_;
};

}  // namespace 

#endif
