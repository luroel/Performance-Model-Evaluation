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

%Datos nuevos para el clasificiador
mdl = ClassificationKNN.fit(X,Y,'NumNeighbors',5);
Xn = wq(11:20,:);
Yn = q(11:20);

Yp = predict(mdl,Xn); %Encuentra a clase de mis nuevos datos (set entrena)

[c,order] = confusionmat(Yn,Yp)
rc = plotroc(Yn,Yp);