#ifndef _ROS_sensor_mannager_sensorData_h
#define _ROS_sensor_mannager_sensorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_mannager
{

  class sensorData : public ros::Msg
  {
    public:
      typedef int8_t _contact1_type;
      _contact1_type contact1;
      typedef int8_t _contact2_type;
      _contact2_type contact2;
      typedef int8_t _contact3_type;
      _contact3_type contact3;
      typedef int8_t _safetyNotOK_type;
      _safetyNotOK_type safetyNotOK;
      typedef int8_t _sensor1Error1_type;
      _sensor1Error1_type sensor1Error1;
      typedef int8_t _sensor1Error2_type;
      _sensor1Error2_type sensor1Error2;
      typedef int8_t _sensor2Error1_type;
      _sensor2Error1_type sensor2Error1;
      typedef int8_t _sensor2Error2_type;
      _sensor2Error2_type sensor2Error2;
      typedef int8_t _sensor3Error1_type;
      _sensor3Error1_type sensor3Error1;
      typedef int8_t _sensor3Error2_type;
      _sensor3Error2_type sensor3Error2;
      typedef int8_t _safetyState_type;
      _safetyState_type safetyState;
      typedef int8_t _sensorICStatus_type;
      _sensorICStatus_type sensorICStatus;
      typedef int8_t _safetyOff_type;
      _safetyOff_type safetyOff;
      typedef int8_t _safetyOk_type;
      _safetyOk_type safetyOk;

    sensorData():
      contact1(0),
      contact2(0),
      contact3(0),
      safetyNotOK(0),
      sensor1Error1(0),
      sensor1Error2(0),
      sensor2Error1(0),
      sensor2Error2(0),
      sensor3Error1(0),
      sensor3Error2(0),
      safetyState(0),
      sensorICStatus(0),
      safetyOff(0),
      safetyOk(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_contact1;
      u_contact1.real = this->contact1;
      *(outbuffer + offset + 0) = (u_contact1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact1);
      union {
        int8_t real;
        uint8_t base;
      } u_contact2;
      u_contact2.real = this->contact2;
      *(outbuffer + offset + 0) = (u_contact2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact2);
      union {
        int8_t real;
        uint8_t base;
      } u_contact3;
      u_contact3.real = this->contact3;
      *(outbuffer + offset + 0) = (u_contact3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact3);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyNotOK;
      u_safetyNotOK.real = this->safetyNotOK;
      *(outbuffer + offset + 0) = (u_safetyNotOK.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safetyNotOK);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1Error1;
      u_sensor1Error1.real = this->sensor1Error1;
      *(outbuffer + offset + 0) = (u_sensor1Error1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor1Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1Error2;
      u_sensor1Error2.real = this->sensor1Error2;
      *(outbuffer + offset + 0) = (u_sensor1Error2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor1Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2Error1;
      u_sensor2Error1.real = this->sensor2Error1;
      *(outbuffer + offset + 0) = (u_sensor2Error1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor2Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2Error2;
      u_sensor2Error2.real = this->sensor2Error2;
      *(outbuffer + offset + 0) = (u_sensor2Error2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor2Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3Error1;
      u_sensor3Error1.real = this->sensor3Error1;
      *(outbuffer + offset + 0) = (u_sensor3Error1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor3Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3Error2;
      u_sensor3Error2.real = this->sensor3Error2;
      *(outbuffer + offset + 0) = (u_sensor3Error2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor3Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyState;
      u_safetyState.real = this->safetyState;
      *(outbuffer + offset + 0) = (u_safetyState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safetyState);
      union {
        int8_t real;
        uint8_t base;
      } u_sensorICStatus;
      u_sensorICStatus.real = this->sensorICStatus;
      *(outbuffer + offset + 0) = (u_sensorICStatus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensorICStatus);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyOff;
      u_safetyOff.real = this->safetyOff;
      *(outbuffer + offset + 0) = (u_safetyOff.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safetyOff);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyOk;
      u_safetyOk.real = this->safetyOk;
      *(outbuffer + offset + 0) = (u_safetyOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safetyOk);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_contact1;
      u_contact1.base = 0;
      u_contact1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact1 = u_contact1.real;
      offset += sizeof(this->contact1);
      union {
        int8_t real;
        uint8_t base;
      } u_contact2;
      u_contact2.base = 0;
      u_contact2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact2 = u_contact2.real;
      offset += sizeof(this->contact2);
      union {
        int8_t real;
        uint8_t base;
      } u_contact3;
      u_contact3.base = 0;
      u_contact3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact3 = u_contact3.real;
      offset += sizeof(this->contact3);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyNotOK;
      u_safetyNotOK.base = 0;
      u_safetyNotOK.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safetyNotOK = u_safetyNotOK.real;
      offset += sizeof(this->safetyNotOK);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1Error1;
      u_sensor1Error1.base = 0;
      u_sensor1Error1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor1Error1 = u_sensor1Error1.real;
      offset += sizeof(this->sensor1Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1Error2;
      u_sensor1Error2.base = 0;
      u_sensor1Error2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor1Error2 = u_sensor1Error2.real;
      offset += sizeof(this->sensor1Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2Error1;
      u_sensor2Error1.base = 0;
      u_sensor2Error1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor2Error1 = u_sensor2Error1.real;
      offset += sizeof(this->sensor2Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2Error2;
      u_sensor2Error2.base = 0;
      u_sensor2Error2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor2Error2 = u_sensor2Error2.real;
      offset += sizeof(this->sensor2Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3Error1;
      u_sensor3Error1.base = 0;
      u_sensor3Error1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor3Error1 = u_sensor3Error1.real;
      offset += sizeof(this->sensor3Error1);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3Error2;
      u_sensor3Error2.base = 0;
      u_sensor3Error2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor3Error2 = u_sensor3Error2.real;
      offset += sizeof(this->sensor3Error2);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyState;
      u_safetyState.base = 0;
      u_safetyState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safetyState = u_safetyState.real;
      offset += sizeof(this->safetyState);
      union {
        int8_t real;
        uint8_t base;
      } u_sensorICStatus;
      u_sensorICStatus.base = 0;
      u_sensorICStatus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensorICStatus = u_sensorICStatus.real;
      offset += sizeof(this->sensorICStatus);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyOff;
      u_safetyOff.base = 0;
      u_safetyOff.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safetyOff = u_safetyOff.real;
      offset += sizeof(this->safetyOff);
      union {
        int8_t real;
        uint8_t base;
      } u_safetyOk;
      u_safetyOk.base = 0;
      u_safetyOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safetyOk = u_safetyOk.real;
      offset += sizeof(this->safetyOk);
     return offset;
    }

    const char * getType(){ return "sensor_mannager/sensorData"; };
    const char * getMD5(){ return "eb973d64b0e43ef46c92c0deaa5e6fcc"; };

  };

}
#endif