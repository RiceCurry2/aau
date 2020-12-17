#ifndef _ROS_sensor_mannager_safetyIO_h
#define _ROS_sensor_mannager_safetyIO_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_mannager
{

  class safetyIO : public ros::Msg
  {
    public:
      typedef int8_t _safetyState_type;
      _safetyState_type safetyState;

    safetyIO():
      safetyState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_safetyState;
      u_safetyState.real = this->safetyState;
      *(outbuffer + offset + 0) = (u_safetyState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safetyState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_safetyState;
      u_safetyState.base = 0;
      u_safetyState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safetyState = u_safetyState.real;
      offset += sizeof(this->safetyState);
     return offset;
    }

    const char * getType(){ return "sensor_mannager/safetyIO"; };
    const char * getMD5(){ return "3ccfc371699155f3bc2b4840a8e3c27d"; };

  };

}
#endif