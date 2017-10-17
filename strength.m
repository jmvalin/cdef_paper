clear;clc;close all;

h = figure(1);
d=-40:.05:40;
plot(d, constraint(d, 2, 5), 'LineWidth', 1.5, d, constraint(d, 4, 5), '--', 'LineWidth', 1.5, d, constraint(d, 8, 5), ':', 'LineWidth', 1.5)
axis([-40, 40, -7.4, 7.4])
grid on
legend('S=2, D=5', 'S=4, D=5', 'S=8, D=5')
xlabel('Pixel difference (d)');
ylabel ('f(d, S, D)');
H = 6; W = 10;
set(h,'PaperUnits','inches')
set(h,'PaperOrientation','portrait');
set(h,'PaperSize',[W,H])
set(h,'PaperPosition',[0,0,W,H])
print(h,'strength.pdf');
