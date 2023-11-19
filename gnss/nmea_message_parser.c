/*
void gpsread_interrupt(){
    if(PIR3bits.RC2IF){
        char rc_byte = RCREG2;
        
        if(rc_byte == '$' || rc_byte == 0xb5){
            gpsread_buffering = 1;
            gpsread_buffer_index = 0;
        }
        
        if(gpsread_buffering){
            gpsread_buffer[gpsread_buffer_index] = rc_byte;
            gpsread_buffer_index += 1;
            if(gpsread_buffer_index == 0xFF){
                // buffer overflow
                gpsread_buffering = 0;
            }
            
            if (rc_byte == '\n' || rc_byte == '\r'){
                // end of NMEA message
                int8_t gpsread_message_write_i = gpsread_message_find_empty();
                if(gpsread_message_write_i >= 0){
                    strcpy(
                        gpsread_messages[gpsread_message_write_i],
                        gpsread_buffer);
                    gpsread_messages_available =
                        gpsread_messages_available | (1 << gpsread_message_write_i);
                }
                gpsread_buffering = 0;
            } else if (
                gpsread_buffer[0] == 0xb5 && 
                gpsread_buffer[1] == 0x62 &&
                gpsread_buffer_index > 6 // after more than 4 bytes read
            ){
                // gps buffered is UBX data
                uint16_t buf_n = 8 + (gpsread_buffer[4] | (gpsread_buffer[5] << 8));
                if(buf_n > 250){
                    gpsread_buffering = 0;
                } else {
                    if(gpsread_buffer_index >= buf_n){
                        int8_t gpsread_message_write_i =
                               gpsread_message_find_empty();

                        if(gpsread_message_write_i >= 0){
                            memcpy(
                                gpsread_messages[gpsread_message_write_i],
                                gpsread_buffer,
                                buf_n
                            );
                            gpsread_messages_available = 
                                gpsread_messages_available | (1 << gpsread_message_write_i);
                            gpsread_buffering = 0;
                        }
                        for(uint8_t i=0; i<0xFF; i++) gpsread_buffer[i] = 0;
                    }
                }
            }
        }
        
        if(!RCSTA2bits.CREN) RCSTA2bits.CREN = 1;
        PIR3bits.RC2IF = 0;
    }
}*/