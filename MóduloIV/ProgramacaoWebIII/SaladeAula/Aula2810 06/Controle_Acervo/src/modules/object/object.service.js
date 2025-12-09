import Object from "./object.model.js";
export const createObject = async (object)=>{
    return Object.create(object);
}
export const findAllObjects = async () =>{
    return Object.findAll()
}
export const update = async (object) =>{
    return Object.update(object, {where: {id: object.id}})
}
export const deleteObjectById = async (objectId) =>{
    return Object.destroy({where: { id: objectId }})
}