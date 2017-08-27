
#include "tftp.h"
void create_ack(unsigned short ack_block, char* ack_buff ){
	unsigned short opcode = ACK;
	opcode = htons(opcode);
	memcpy(ack_buff,&opcode,2);
	memcpy(ack_buff+2,&ack_block,2);
}
char * create_request(unsigned short opcode, char* filename, char* mode){
	int packetLen = 4 + strlen(filename) + strlen(mode);
    char *packet = (char*)calloc(packetLen,sizeof(char));
    unsigned short op_code = opcode;
    op_code = htons(op_code);
    memcpy(packet,&op_code,2);
    //store the filename
    strcpy(packet+2, filename);

    //store the mode
    strcpy(packet+2+strlen(filename)+1 , mode);

    return packet;

}
void create_data(unsigned short data_block, char* data_buff){

}
void create_error(unsigned short errorCode);