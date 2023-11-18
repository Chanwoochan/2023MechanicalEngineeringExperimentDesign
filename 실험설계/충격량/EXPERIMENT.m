clear all; clc;
delete(instrfindall);


s2 = serial('COM4', 'BaudRate', 57600); 
fopen(s2); 

time = 0;
datalen = 500;
t = zeros(1,datalen);
data = zeros(1,datalen);

while (1)
    time = time + 1;
    pat = ",";
    scan = fscanf(s2);
    if extractBetween(scan,"[","]")=="Slave1" & size(strfind(scan,"F"))==1
           if contains(scan,":") & contains(scan,",") 
                str_t = extractBetween(scan,":",pat);
                str_a = extractBetween(scan,pat,"F");

                pars_t = str2double(str_t);
                pars_a = str2double(str_a);

                t(1:end-1) = t(2:end);
                t(end) = pars_t;

                data(1:end-1) = data(2:end);
                data(end) = pars_a;
                
                idx = time-datalen+1:1:time;
                plot(t, data, 'linewidth', 2, 'Marker','*');
                axis([min(t) max(t) -10 10]);
                drawnow; 
           end
    end
    if extractBetween(scan,"[","]")=="Master"
        call = str2num(extractAfter(scan,":"));
        if call == 1004
            break
        end
    end
end

t = t - t(1);
RESULT = [t;data];

fclose(s2) 
delete(instrfindall)