if __name__ == '__main__':
	
    file_size = 4 * 1024 * 1024 + 1
    
    file_data = bytearray([0] * file_size)

    for offset in [0, 10000, file_size - 1]:
        file_data[offset] = 1

    with open('fileA', mode='wb') as file:
        file.write(file_data)


