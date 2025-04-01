#!/bin/bash
cd /home/ec2-user/MyFakeGameServer/build
nohup ./gateway/gateway &> gateway.log &
nohup ./zone/zone &> zone.log &
nohup ./chat/chat &> chat.log &