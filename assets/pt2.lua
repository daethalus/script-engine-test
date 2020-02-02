function printMsg()
	printMessage("1from lua alterado")
end



function sum(player)	

	functions.printMessage("asd");

	print("sum lua called")
	player:sumValue(sumNumbers(100,100))
	print("from lua: " .. player:getValue())
	player:sumValue(100)

	print("trying" .. player.pValue);

	print("trying to crate new player ;O")

	p = Player()
	print("new p lua: " .. p:getValue())
	p:sumValue(100)
	print("new p lua new value : " .. p:getValue())
end 