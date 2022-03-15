/*
 * Copyright (C) 2022 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef IGNITION_GAZEBO_MSGMANAGER_HH_
#define IGNITION_GAZEBO_MSGMANAGER_HH_

#include <ignition/msgs/datagram.pb.h>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <ignition/transport/Node.hh>
#include <ignition/utils/ImplPtr.hh>

#include "ignition/gazebo/config.hh"
#include "ignition/gazebo/System.hh"

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace comms
{
struct MsgContent
{
  /// \brief Queue of inbound messages.
  public: std::deque<std::shared_ptr<msgs::Datagram>> inboundMsgs;

  /// \brief Queue of outbound messages.
  public: std::deque<std::shared_ptr<msgs::Datagram>> outboundMsgs;

  /// \brief A map where the key is the topic subscribed to this address and
  /// the value is a publisher to reach that topic.
  public: std::map<std::string,
                   ignition::transport::Node::Publisher> subscriptions;
};

/// \brief
class MsgManager
{
  /// \brief Default constructor.
  public: MsgManager();

  /// \brief Destructor.
  public: virtual ~MsgManager();

  /// \brief
  public: void AddSubscriber(const std::string &_address,
                             const std::string &_topic);

  /// \brief
  // public: std::unordered_set<std::string> Subscribers(
  //   const std::string &_address);

  /// \brief
  public: void AddInbound(const std::string &_address,
                          const std::shared_ptr<msgs::Datagram> &_msg);

  /// \brief
  public: void AddOutbound(const std::string &_address,
                           const std::shared_ptr<msgs::Datagram> &_msg);

  /// \brief
  public: bool RemoveSubscriber(const std::string &_address,
                                const std::string &_topic);

  /// \brief
  public: void RemoveInbound(const std::string &_address,
                             const std::shared_ptr<msgs::Datagram> &_msg);

  /// \brief
  public: void RemoveOutbound(const std::string &_address,
                              const std::shared_ptr<msgs::Datagram> &_msg);

  /// \brief ToDo.
  public: void DeliverMsgs();

  /// \brief ToDo.
  public: std::map<std::string, MsgContent> &Data();

  /// \brief ToDo.
  public: std::map<std::string, MsgContent> Copy();

  /// \brief ToDo.
  public: void Set(std::map<std::string, MsgContent> &_newContent);

  /// \brief Private data pointer.
  IGN_UTILS_UNIQUE_IMPL_PTR(dataPtr)
};
}
}
}
}

#endif