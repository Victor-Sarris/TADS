import express from "express";
import {newCollection, listCollections, deleteCollection, updateCollection } from "./collection.controller.js"
import {authenticate, authorizaAdmin} from "../../middleware/authenticate.js"

const collectionRouter = express.Router();
collectionRouter.get("/collections", authenticate, listCollections)
collectionRouter.post("/collections", authenticate,  authorizaAdmin, newCollection)
collectionRouter.post("/collections/update", authenticate, authorizaAdmin, updateCollection)
collectionRouter.post("/collections/delete", authenticate, authorizaAdmin, deleteCollection )

export default collectionRouter; 