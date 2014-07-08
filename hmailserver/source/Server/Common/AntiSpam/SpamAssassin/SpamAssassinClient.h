// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../../TCPIP/AnsiStringConnection.h"

namespace HM
{
   class File;

   class SpamAssassinClient : public AnsiStringConnection
   {
   public:
      SpamAssassinClient(const String &sFile, bool useSSL,
         boost::asio::io_service& io_service, 
         boost::asio::ssl::context& context,
         String &message,
         bool &testCompleted);
      ~SpamAssassinClient(void);

      virtual void ParseData(const AnsiString &Request);
      virtual void ParseData(shared_ptr<ByteBuffer> pBuf);

      bool FinishTesting();

      
   protected:

      virtual void OnCouldNotConnect(const AnsiString &sErrorDescription);
      virtual void OnReadError(int errorCode);
      virtual void OnConnected();
      virtual AnsiString GetCommandSeparator() const;
      virtual void OnConnectionTimeout();
      virtual void OnExcessiveDataReceived();

   private:

      int _ParseFirstBuffer(shared_ptr<ByteBuffer> pBuffer) const;
      bool _SendFileContents(const String &sFilename);

      String m_sCommandBuffer;

      String m_sMessageFile;
	   int m_iSpamDSize;
	   int m_iMessageSize;
      shared_ptr<File> m_pResult;

      String &m_sMessage;
      bool &m_TestCompleted;
  };
}