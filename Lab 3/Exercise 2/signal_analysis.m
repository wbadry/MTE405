% //  .___  ___. .___________. _______     _  _      ___    _____
% //  |   \/   | |           ||   ____|   | || |    / _ \  | ____|
% //  |  \  /  | `---|  |----`|  |__      | || |_  | | | | | |__
% //  |  |\/|  |     |  |     |   __|     |__   _| | | | | |___ \
% //  |  |  |  |     |  |     |  |____       | |   | |_| |  ___) |
% //  |__|  |__|     |__|     |_______|      |_|    \___/  |____/
% //
% //   __          ___      .______       ____
% //  |  |        /   \     |   _  \     |___ \
% //  |  |       /  ^  \    |  |_)  |      __) |
% //  |  |      /  /_\  \   |   _  <      |__ <
% //  |  `----./  _____  \  |  |_)  |     ___) |
% //  |_______/__/     \__\ |______/     |____/
% //
% //  Code created by : Waleed El-Badry
% //  DATE : 11/03/2019

%% Clear workspace
clc;
clear variables;
close all;

%% Read LM35 noisy temperature
temp = csvread('LM_log.csv');

%% Genereate time stamp
dt = 100.0E-3; % 100 ms
t  = 0 : dt : (length(temp) -1) * dt;

%% Find measurements common characteristics
temp_mu = mean(temp);
temp_std = std(temp);
temp_norm = (temp - temp_mu) / temp_std;
temp_mu_norm = mean(temp_norm);
temp_std_norm = std(temp_norm);

%% Plot Noisy temperature
figure('Name','LM 35 temperature');
subplot(2,1,1)
plot(t,temp,'r'),...
    xlabel('Time (s)'),ylabel('Temperature °C'),...
    title(['Acquired Temperature ' 'Mu=' num2str(temp_mu) ' , std=' num2str(temp_std)]);
subplot(2,1,2)
plot(t,temp_norm),...
    xlabel('Time (s)'),ylabel('Temperature °C'),...
    title(['Normalized Temperature ' 'Mu=' num2str(temp_mu_norm) ' , std=' num2str(temp_std_norm)]);
