clear all; clc;

delete(instrfindall) 

s2 = serial('COM4', 'BaudRate', 115200); 

fopen(s2); 

time = 0;

datalen = 100;
t = zeros(1,datalen);
data = zeros(1,datalen);
% for i = 1:datalen;

while (1)

    time = time + 1;
    
    pat = ",";
    scan = fscanf(s2);
    if extractBetween(scan,"[","]")=="Slave1"
        pars_t = str2double(extractBetween(scan,":",pat));
        pars_a = str2double(extractAfter(scan,pat));
    
        t(1:end-1) = t(2:end);
        t(end) = pars_t;
        data(1:end-1) = data(2:end);
        data(end) = pars_a;
    
        idx = time-datalen+1:1:time;
    
        plot(t, data, 'linewidth', 2);
    
        axis([min(t) max(t) -10 10]);
    
        drawnow; 
    end
    if extractBetween(scan,"[","]")=="Master"
        call = str2num(extractAfter(scan,":"));
        if call == 1004
            break
        end
    end
end

fclose(s2) 

delete(instrfindall) 