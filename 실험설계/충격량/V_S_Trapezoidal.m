clc
datanum=300;

EXP_NO = 1;
BEAM_NO = 4;
start = 1;

filename = "DATA-"+ EXP_NO + "-" + BEAM_NO +".csv";

res = readmatrix(filename);
fprintf("EXP_NO: %d, BEAM_NO: %d\n",res(1,datanum+1),res(2,datanum+1))
fprintf("START_ARRDUINO_TIME: %.3f\n",res(1,start))

fig = figure(1);

[peaka, peakindex] = max(abs(res(2,start:datanum)))
peakt = res(1,peakindex);

plot(res(1,start:datanum)-peakt+1, res(2,start:datanum), 'linewidth', 2, "Color", "black")
title("EXP_ NO: "+res(1,datanum+1)+", BEAM_ NO: "+res(2,datanum+1));
ylabel("acceleration (m/s^2)");
xlabel("time (sec)");
xlim([0 2])
grid();

avg = sum(res(2, 150:200)) / 51;
avg