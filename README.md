Arduino-to-Arduino-Serial
=========================

This is a simple example of an Arduino to Arduino serial communication protocol. The sender packetizes the data with a sync byte, payload, and checksum. The reciever watches for the sync byte, reads in the data, and validates the checksum.
