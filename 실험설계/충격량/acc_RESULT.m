clc
datanum=300;

EXP_NO = 1;
BEAM_NO = 1;
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

hold on
plot(1, -peaka, "rx", "MarkerSize", 10, "LineWidth", 2);
peakstr = ""+(-peaka);
text(1.1,-peaka+0.1, peakstr, "FontSize", 12 ,"Color", "red", "FontWeight", "bold");
%plot([0;0], [-10;10], 'linewidth', 2, "Color", "red");
%plot([t(end);t(end)], [-10;10], 'linewidth', 2, "Color", "blue");
hold off

img_filename = "DATA_Figure-"+ EXP_NO + "-" + BEAM_NO + ".png"
exportgraphics(fig, img_filename, 'Resolution', 1280)
