//----------------------------------------------
/* ENCYPTION MAIN 
/* AND ITS API                                */
/* THIS PROGRAM IS PROGRAMMED FOR WIZGATE     */
/* BUT ALL COPYRIGHT RESERVED BY JIYOON CHUNG */
/* (c) ABLEX AND OHSUNGINC 2001.6.1           */
/* Classed by ks2000 2001.6.1				  */	
/* Add by ks2000 2003.6.7 crc32버젼...		  */	
#ifndef __CJVCRYPTION_H
#define __CJVCRYPTION_H

typedef unsigned char 	T_OCTET;
typedef _int64			T_KEY;


class CJvCryption
{
private:
	T_KEY m_public_key;
	T_KEY m_private_key;
	T_KEY m_tkey;

public:
	CJvCryption();
	~CJvCryption();

	void SetPublicKey(T_KEY pk);
	void SetPrivateKey(T_KEY pk);

	void Init();

	void JvEncryption(T_KEY private_key, int len, T_OCTET *datain, T_OCTET *dataout);
	void JvDecryption(T_KEY private_key, int len, T_OCTET *datain, T_OCTET *dataout);

	void JvEncryption( int len, T_OCTET *datain, T_OCTET *dataout );
	void JvDecryption( int len, T_OCTET *datain, T_OCTET *dataout );
	void JvEncryptionA( int len, T_OCTET *datain, T_OCTET *dataout );
	void JvDecryptionA( int len, T_OCTET *datain, T_OCTET *dataout );

	unsigned long crc32c(unsigned char Octet,unsigned long dwCrc);
	unsigned long crc32c(unsigned char *pBuf, int size,unsigned long dwCrc);
	unsigned long crc32a(unsigned char *pBuf, int size,unsigned long dwCrc);

	// 원래 데이타보다 4바이트 큰 버퍼를 입력으로 넣어야함...
	void JvEncryptionWithCRC32a( int len, T_OCTET *datain, T_OCTET *dataout );
	void JvEncryptionWithCRC32( int len, T_OCTET *datain, T_OCTET *dataout );

	// CRC32값을 제외한 실제 데이타 크기를 리턴함...
	int JvDecryptionWithCRC32a( int len, T_OCTET *datain, T_OCTET *dataout );
	int JvDecryptionWithCRC32( int len, T_OCTET *datain, T_OCTET *dataout );

};

#endif
