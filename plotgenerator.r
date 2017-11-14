
library(ggplot2)   
tabla=read.table("plot5n1000000000000.txt")
n=tabla$V1
Tiempo=tabla$V2
df <- data.frame(x=seq(1, e9, length.out=1000000000000))
ggplot(data = tabla, aes(x=n, y=Tiempo)) +  geom_point()   + ggtitle("Tiempo vs n para n = 1000000000000") + theme(plot.title = element_text(hjust = 0.5))
#+ scale_y_continuous(breaks = seq(min(Tiempo), max(Tiempo),0.0001))
