import Collection from "./collection.model.js";
export const createCollection = async (collection)=>{
    return Collection.create(collection);
}
export const findAllCollections = async () =>{
    return Collection.findAll()
}
export const update = async (collection) =>{
    return Collection.update(collection, {where: {id: collection.id}})
}
export const deleteCollectionById = async (collectionId) =>{
    return Collection.destroy({where: { id: collectionId }})
}