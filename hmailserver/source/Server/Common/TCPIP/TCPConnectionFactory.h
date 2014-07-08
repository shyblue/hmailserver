// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "TCPConnection.h"


namespace HM
{
   class TCPConnectionFactory
   {
   public:
      virtual shared_ptr<TCPConnection> Create(bool useSSL,
         boost::asio::io_service& io_service, 
         boost::asio::ssl::context& context) = 0;
   };

   class SMTPConnectionFactory : public TCPConnectionFactory
   {
   public:
      virtual shared_ptr<TCPConnection> Create(bool useSSL,
         boost::asio::io_service& io_service, 
         boost::asio::ssl::context& context);
   };

   class POP3ConnectionFactory : public TCPConnectionFactory
   {
   public:
      virtual shared_ptr<TCPConnection> Create(bool useSSL,
         boost::asio::io_service& io_service, 
         boost::asio::ssl::context& context);
   };

   class IMAPConnectionFactory : public TCPConnectionFactory
   {
   public:
      virtual shared_ptr<TCPConnection> Create(bool useSSL,
         boost::asio::io_service& io_service, 
         boost::asio::ssl::context& context);
   };

}