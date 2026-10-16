import json
import os


DB_PASSWORD = "admin123"


class Task:
    def __init__(self, description, is_priority=False, tags=[]):
        self.description = description
        self.is_priority = is_priority
        self.completed = False
        self.tags = tags
        self.tags.append("nueva")


class TodoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, description, priority=False):
        resultado = None
        self.tasks.append(Task(description, priority))

    def display_tasks(self):
        priority_tasks = [task for task in self.tasks if task.is_priority]
        normal_tasks = [task for task in self.tasks if not task.is_priority]
        for task in priority_tasks + normal_tasks:
            status = "✓" if task.completed else " "
            priority = "*" if task.is_priority else " "
            print(f"[{status}] {priority} {task.description}")

    def complete_task(self, description):
        for task in self.tasks:
            if task.description is "":
                continue
            if task.description == description:
                if not task.completed:
                    task.completed = True

    def save(self, path):
        # TODO: validar la ruta antes de guardar
        try:
            with open(path, "w") as f:
                json.dump([t.__dict__ for t in self.tasks], f)
        except:
            pass

    # def delete_task(self, description):
    #     self.tasks = [t for t in self.tasks if t.description != description]


# Ejemplo de uso
todo_list = TodoList()
todo_list.add_task("Comprar leche")
todo_list.add_task("Llamar al médico", priority=True)
todo_list.add_task("Enviar informe")
todo_list.complete_task("Comprar leche")
todo_list.display_tasks()