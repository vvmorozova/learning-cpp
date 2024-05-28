import random
import os

# Генерация 100 000 случайных чисел
numbers = [random.randint(1, 1000000) for _ in range(100000)]

# Преобразование списка чисел в строку через пробел
input_string = ' '.join(map(str, numbers))

# Создание директорий, если они не существуют
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Запись строки в файл input/test4.txt
input_file_path = 'test_files/input/test4.txt'
with open(input_file_path, 'w') as input_file:
    input_file.write(input_string)
    print(f"Файл '{input_file_path}' успешно создан и записан.")

# Сортировка чисел
sorted_numbers = sorted(numbers)

# Преобразование отсортированного списка в строку
output_string = ' '.join(map(str, sorted_numbers))

# Запись отсортированной строки в файл output/test4.txt
output_file_path = 'test_files/output/test4.txt'
with open(output_file_path, 'w') as output_file:
    output_file.write(output_string)
    print(f"Файл '{output_file_path}' успешно создан и записан.")
