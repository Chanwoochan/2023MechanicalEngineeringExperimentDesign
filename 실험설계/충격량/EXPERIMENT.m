clear all; clc;
delete(instrfindall);

EXP_NO = 2;
BEAM_NO = 1;
% 실험대상과실험번호지정

filename = "DATA-"+ EXP_NO + "-" + BEAM_NO +".csv"; %저장할파일이름

s2 = serial('/dev/ttyUSB0', 'BaudRate', 57600); 
fopen(s2);  %아두이노와 통신

time = 0;
datalen = 300;
first = 0;
t = zeros(1,datalen);
data = zeros(1,datalen);

while (1)
    time = time + 1;
    scan = fscanf(s2);
    fprintf(scan)
    if extractBetween(scan,"[","]")=="Slave1" & size(strfind(scan,"F"))==1 & size(strfind(scan,":"))==1 & size(strfind(scan,","))==1
           if extractAfter(scan,"F")==""
                str_t = extractBetween(scan,":",",");
                str_a = extractBetween(scan,",","F");        % 데이터를파싱 후 전송이 잘못 된 데이터는 무시

                pars_t = str2double(str_t);
                pars_a = str2double(str_a);

                if ~isnan(pars_a) & ~isnan(pars_b)
                    t(1:end-1) = t(2:end);
                    t(end) = pars_t;
    
                    data(1:end-1) = data(2:end);
                    data(end) = pars_a;
                    
                    idx = time-datalen+1:1:time;
    
                    axis([min(t) max(t) -10 10]);              % 데이터 300 개 저장
                end
           end
    end
    if extractBetween(scan,"[","]")=="Master"
        call = str2num(extractAfter(scan,":"));
        if call == 1004                                    % 1004 버튼을 누를 시 실험 종료 
            break
        end
    end
    if extractBetween(scan,"[","]")=="Master"
        call = str2num(extractAfter(scan,":"));
        if call == 1000                                    % 1000 버튼을 누를 시 실험 시작
            first = t(end-1);
        end
    end    
end

t = t - first;
RESULT = [t,EXP_NO;data,BEAM_NO];
plot(t, data, 'linewidth', 2, "Color", "black");          %결과플롯
hold on
hold off
writematrix(RESULT,filename)                              %파일저장

fclose(s2) 
delete(instrfindall)                                      %20191089김찬우