import Person from "./person.model.js";
export const createPerson = async (person)=>{
    return Person.create(person);
}
export const findAllPersons = async () =>{
    return Person.findAll()
}
export const update = async (person) =>{
    return Person.update(person, {where: {id: person.id}})
}
export const deletePersonById = async (personId) =>{
    return Person.destroy({where: { id: personId }})
}