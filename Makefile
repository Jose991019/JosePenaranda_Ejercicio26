Resultado.png: grafica.py euler.dat RK4.dat leap_frog.dat
	python grafica.py
    
euler.dat RK4.dat leap_frog.dat: JosePenaranda_Ejercicio26.x
	./JosePenaranda_Ejercicio26.x

JosePenaranda_Ejercicio26.x: JosePenaranda_Ejercicio26.cpp
	c++ JosePenaranda_Ejercicio26.cpp -o JosePenaranda_Ejercicio26.x

clean:
	rm -rf *.x *.dat Resultado.png
