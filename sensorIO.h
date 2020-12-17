#ifndef _ROS_sensor_mannager_sensorIO_h
#define _ROS_sensor_mannager_sensorIO_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_mannager
{

  class sensorIO : public ros::Msg
  {
    public:
      typedef int8_t _sensor1IO_type;
      _sensor1IO_type sensor1IO;
      typedef int8_t _sensor2IO_type;
      _sensor2IO_type sensor2IO;
      typedef int8_t _sensor3IO_type;
      _sensor3IO_type sensor3IO;

    sensorIO():
      sensor1IO(0),
      sensor2IO(0),
      sensor3IO(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1IO;
      u_sensor1IO.real = this->sensor1IO;
      *(outbuffer + offset + 0) = (u_sensor1IO.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor1IO);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2IO;
      u_sensor2IO.real = this->sensor2IO;
      *(outbuffer + offset + 0) = (u_sensor2IO.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor2IO);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3IO;
      u_sensor3IO.real = this->sensor3IO;
      *(outbuffer + offset + 0) = (u_sensor3IO.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor3IO);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sensor1IO;
      u_sensor1IO.base = 0;
      u_sensor1IO.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor1IO = u_sensor1IO.real;
      offset += sizeof(this->sensor1IO);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor2IO;
      u_sensor2IO.base = 0;
      u_sensor2IO.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor2IO = u_sensor2IO.real;
      offset += sizeof(this->sensor2IO);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor3IO;
      u_sensor3IO.base = 0;
      u_sensor3IO.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor3IO = u_sensor3IO.real;
      offset += sizeof(this->sensor3IO);
     return offset;
    }

    const char * getType(){ return "sensor_mannager/sensorIO"; };
    const char * getMD5(){ return "8b72547197d27f7030ab237336a8b6ac"; };

  };

}
#endif