/****************************************************************************
*     Copyright (C) 2017 by KPIT Technologies                     *
*                                                                           *
****************************************************************************/

/**
* @file      publish_subscribe.h
*
* @author    Sujeyendra Tummala (Tummala.Sujeyendra@kpit.com)
*
* @date      18-Oct-2017
*
* @brief     This file declares the Receiver callback and Publish subscribe 
*            class that implements the communication interface class
**/

#ifndef PUBLISHER_SUBSCRIBE_H
#define PUBLISHER_SUBSCRIBE_H

/*! Include Files */
#include "ros_arithmetic/app/multiplier_node_handler.h"
#include "ros_arithmetic/core/communication_interface.h"
#include "ros/ros.h"
#include "ros_ran_num_msg/rand_num.h"
#include "ros_ran_num_msg/mutliplier_num.h"

/*! Class Declarations */
class ReceiverCallback {
 public:
  /**
  * Function name: Constructor
  *
  * @brief      Constructor to the receiver callback class that 
  *             assigns the multiplier node handle reference to 
  *             the received reference
  *
  * @param[in]  ArithmeticNodeHandlerInterface*
  *              Pointer to the reference multiplier node handler  
  **/
  explicit ReceiverCallback(ArithmeticNodeHandlerInterface* node_handler);

  /**
  * Function name: Destructor
  *
  * @brief      Destructor to the receiver callback class
  **/
  ~ReceiverCallback();

  /**
  * Function name: MultiplierCallback
  *
  * @brief      Declaration to the callback function that get the multiplier
  *             of received values
  *
  * @param[in]  ros_ran_num_msg::rand_num::ConstPtr& value
  *              Holds the value of received rand_num message
  *              of type ros_ran_num_msg
  *
  * @param[out] None
  *
  * @return     Void
  *
  **/
  void MultiplierCallback(const ros_ran_num_msg::rand_num::ConstPtr& value);

 private:
  /*! Holds the reference of the multiplier node handler */
  ArithmeticNodeHandlerInterface *arithmetic_node_handler_;

  /** Holds the reference to the publisher object */
  ros::Publisher multiplier_publisher_;

  /** Holds the reference of the nodehandle object */
  ros::NodeHandle node_handle_multiplier_;
};

/*! Class Declarations */
class PublishSubscribe : public CommunicationInterface {
 public:
  /**
  * Function name: Constructor
  *
  * @brief      Constructor to the publishSubsribe class that 
  *             creates an object of receiver callback class and 
  *             assigns the received multiplier node handle reference to 
  *             reference callback class
  *
  * @param[in]  ArithmeticNodeHandlerInterface*
  *              Pointer to the reference multiplier node handler
  **/
  explicit PublishSubscribe(ArithmeticNodeHandlerInterface* node_handler);

  /**
  * Function name: Destructor
  *
  * @brief      Destructor to the PublishSubscribe class
  **/
  ~PublishSubscribe();

  /**
  * Function name: SendMessage
  *
  * @brief      Declares the functionality to send the message
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     Void
  **/
  void SendMessage();

  /**
  * Function name: ReceiveMessage
  *
  * @brief      Declares the functionality to receive the message through ros subscribe
  *             and calls the receiver callback function
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     Void
  *
  **/
  void ReceiveMessage();

 private:
  /** Holds the reference to the receiver callback object */
  ReceiverCallback *receiver_callback_;

  /** Holds the reference to the multiplier node handler object */
  ArithmeticNodeHandlerInterface *arithmetic_node_handler_;

  /** Holds the reference of the nodehandle object */
  ros::NodeHandle node_handle_;

  /** Holds the reference to the subscriber object */
  ros::Subscriber multiplier_subscriber_;
};

#endif /* PUBLISHER_SUBSCRIBE_H */

