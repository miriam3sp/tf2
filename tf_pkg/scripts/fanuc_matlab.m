% Comau Smart-Six forward kinematics

q = zeros(6,1); %joint variables

dh_params = [   0.525,      q(1),       0.150,   -pi/2;
                0,          q(2)-pi/2,  0.790,   0;
                0,          q(3),       0.150,   -pi/2;
                0.860,      q(4),       0,      pi/2;
                0,          q(5),       0,      -pi/2;
                0.100,      q(6),       0,      0       ]; %D-H parameters
            
% tz*Rz*tx*Rx
T01 = trvec2tform([0, 0, dh_params(1,1)]) * rotm2tform(rotz(rad2deg(dh_params(1,2)))) * trvec2tform([dh_params(1,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(1,4))));
T12 = trvec2tform([0, 0, dh_params(2,1)]) * rotm2tform(rotz(rad2deg(dh_params(2,2)))) * trvec2tform([dh_params(2,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(2,4))));
T23 = trvec2tform([0, 0, dh_params(3,1)]) * rotm2tform(rotz(rad2deg(dh_params(3,2)))) * trvec2tform([dh_params(3,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(3,4))));
T34 = trvec2tform([0, 0, dh_params(4,1)]) * rotm2tform(rotz(rad2deg(dh_params(4,2)))) * trvec2tform([dh_params(4,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(4,4))));
T45 = trvec2tform([0, 0, dh_params(5,1)]) * rotm2tform(rotz(rad2deg(dh_params(5,2)))) * trvec2tform([dh_params(5,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(5,4))));
T56 = trvec2tform([0, 0, dh_params(6,1)]) * rotm2tform(rotz(rad2deg(dh_params(6,2)))) * trvec2tform([dh_params(6,3), 0, 0]) * rotm2tform(rotx(rad2deg(dh_params(6,4))));


T46 = T45*T56;
T36 = T34*T46;
T26 = T23*T36;
T16 = T12*T26;
T06 = T01*T16;


% From frame5 to frame6
t56 = tform2trvec(T56)
R56 = tform2rotm(T56)
rpy_56 = rotm2eul(R56)
aa56 = rotm2axang(R56)

% From frame4 to frame6
t46 = tform2trvec(T46) 
R46 = tform2rotm(T46) 
rpy_46 = rotm2eul(R46);
aa46 = rotm2axang(R46);

% From frame3 to frame6
t36 = tform2trvec(T36) 
R36 = tform2rotm(T36)
rpy_36 = rotm2eul(R36)
aa36 = rotm2axang(R36)

% From frame2 to frame6
t26 = tform2trvec(T26) 
R26 = tform2rotm(T26) 
rpy_26 = rotm2eul(R26)
aa26 = rotm2axang(R26)

% From frame1 to frame6
t16 = tform2trvec(T16) 
R16 = tform2rotm(T16)
rpy_16 = rotm2eul(R16)
aa16 = rotm2axang(R16)

% From base_frame to frame6
t06 = tform2trvec(T06)
R06 = tform2rotm(T06)
rpy_06 = rotm2eul(R06)
aa06 = rotm2axang(R06)














