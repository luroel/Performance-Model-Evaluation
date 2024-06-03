clear all
clc
close all

wq = readtable('winequality20n2.csv');
q = readtable('winequality20n3.csv');
%--------------------------Set de entrenamiento---------------------------%
p=randperm(20);
wq = wq(p,:);
q = table2array(q); %Convierte tabla a array
q=q(p);

X = wq(1:10,:);
Y = q(1:10);

